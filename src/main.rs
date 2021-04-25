/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-21 18:43:44
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-31 12:05:21
 * @Description: GUI Implementation
 */
use iced::{
    button, pick_list, text_input, Align, Button, Column, Element, PickList, Row, Sandbox,
    Settings, Text, TextInput,
};

use nfd::Response;

extern crate hw01;
use crate::hw01::*;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Cipher {
    Caeser,
    Railfence,
    Polybius,
}

impl Cipher {
    const ALL: [Cipher; 3] = [Cipher::Caeser, Cipher::Railfence, Cipher::Polybius];
}

impl Default for Cipher {
    fn default() -> Cipher {
        Cipher::Caeser
    }
}

impl std::fmt::Display for Cipher {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                Cipher::Caeser => "Caeser Cipher",
                Cipher::Railfence => "Railfence Cipher",
                Cipher::Polybius => "Polybius Cipher",
            }
        )
    }
}

#[derive(Default)]
struct Counter {
    pick_list: pick_list::State<Cipher>,
    selected_cipher: Cipher,

    cleartext_content: String,
    cleartext: text_input::State,

    ciphertext_content: String,
    ciphertext: text_input::State,

    key: text_input::State,
    key_content: String,

    encryptbutton_state: button::State,
    decryptbutton_state: button::State,

    cleartext_read_button_state: button::State,
    cleartext_write_button_state: button::State,
    ciphertext_read_button_state: button::State,
    ciphertext_write_button_state: button::State,

    result: String,
}

#[derive(Debug, Clone)]
enum Message {
    CipherSelected(Cipher),
    ClearTextChanged(String),
    CipherTextChanged(String),
    KeyChanged(String),
    ResultChanged(String),
    Encrypt,
    Decrypt,
    ReadClearTextFromFile,
    WriteClearTextToFile,
    ReadCipherTextFromFile,
    WriteCipherTextToFile,
}

impl Sandbox for Counter {
    type Message = Message;

    fn new() -> Self {
        Self::default()
    }

    fn title(&self) -> String {
        String::from("Cipher")
    }

    fn update(&mut self, message: Message) {
        match message {
            Message::CipherSelected(cipher) => {
                self.selected_cipher = cipher;
            }
            Message::ClearTextChanged(cleartext) => self.cleartext_content = cleartext,
            Message::CipherTextChanged(ciphertext) => self.ciphertext_content = ciphertext,
            Message::KeyChanged(key) => {
                if key.parse::<i32>().is_ok() || key.is_empty() {
                    self.key_content = key
                }
            }
            Message::ResultChanged(result) => {
                self.result = result;
            }
            Message::Encrypt => {
                self.update(Message::ResultChanged(String::from("")));
                let key = self.key_content.parse::<i32>();
                if key.is_err() && self.selected_cipher!=Cipher::Polybius {
                    self.update(Message::ResultChanged(format!(
                        "Error: invalid key:<{:?}>",
                        key.err()
                    )));
                    return;
                }
                let t = match self.selected_cipher {
                    Cipher::Caeser => caeser::encrypt(
                        &self.cleartext_content,
                        self.key_content.parse::<i32>().unwrap(),
                    ),
                    Cipher::Railfence => railfence::encrypt(
                        &self.cleartext_content,
                        self.key_content.parse::<i32>().unwrap()
                    ),
                    Cipher::Polybius => polybius::encrypt(
                        &self.cleartext_content,
                    ),
                };
                let t = match t {
                    Some(t) => t,
                    None => {
                        self.update(Message::ResultChanged(String::from(
                            "Error: invalid parameters provided.",
                        )));
                        String::from("")
                    }
                };
                self.update(Message::CipherTextChanged(t));
            }
            Message::Decrypt => {
                self.update(Message::ResultChanged(String::from("")));
                let key = self.key_content.parse::<i32>();
                if key.is_err() && self.selected_cipher!=Cipher::Polybius {
                    self.update(Message::ResultChanged(format!(
                        "Error: invalid key:<{:?}>",
                        key.err()
                    )));
                    return;
                }
                let t = match self.selected_cipher {
                    Cipher::Caeser => caeser::decrypt(
                        &self.ciphertext_content,
                        self.key_content.parse::<i32>().unwrap(),
                    ),
                    Cipher::Railfence => railfence::decrypt(
                        &self.ciphertext_content,
                        self.key_content.parse::<i32>().unwrap(),
                    ),
                    Cipher::Polybius => polybius::decrypt(
                        &self.ciphertext_content,
                    ),
                };
                let t = match t {
                    Some(t) => t,
                    None => {
                        self.update(Message::ResultChanged(String::from(
                            "Error: invalid parameters provided.",
                        )));
                        String::from("")
                    }
                };
                self.update(Message::ClearTextChanged(t));
            }
            Message::ReadClearTextFromFile => {
                //@TODO
                let result = nfd::open_file_dialog(None, None).unwrap_or_else(|e| {
                    panic!(e);
                });
                match result {
                    Response::Okay(file_path) => match reader::read(&file_path) {
                        Ok(s) => {
                            self.cleartext_content = s;
                            self.update(Message::ResultChanged(String::from(
                                "ReadClearTextFromFile: Success",
                            )))
                        }
                        Err(why) => self.update(Message::ResultChanged(format!(
                            "ReadClearTextFromFile: Error occured: {:?}",
                            why
                        ))),
                    },
                    Response::OkayMultiple(_files) => {
                        self.update(Message::ResultChanged(String::from(
                            "ReadClearTextFromFile: Not supposed to read from multiple files.",
                        )));
                    }
                    Response::Cancel => {
                        self.update(Message::ResultChanged(String::from(
                            "ReadClearTextFromFile: User canceled.",
                        )));
                    }
                }
            }
            Message::WriteClearTextToFile => {
                //@TODO
                let result = nfd::open_file_dialog(None, None).unwrap_or_else(|e| {
                    panic!(e);
                });
                match result {
                    Response::Okay(file_path) => {
                        match writer::write(&file_path, &self.cleartext_content) {
                            Ok(_t) => {
                                self.update(Message::ResultChanged(String::from(
                                    "WriteClearTextToFile: Success",
                                )));
                            }
                            Err(why) => {
                                self.update(Message::ResultChanged(format!(
                                    "WriteClearTextToFile: Error occured: {:?}",
                                    why
                                )));
                            }
                        }
                    }
                    Response::OkayMultiple(_files) => {
                        self.update(Message::ResultChanged(String::from(
                            "WriteClearTextToFile: Not supposed to read from multiple files.",
                        )));
                    }
                    Response::Cancel => {
                        self.update(Message::ResultChanged(String::from(
                            "WriteClearTextToFile: User canceled.",
                        )));
                    }
                }
            }
            Message::ReadCipherTextFromFile => {
                //@TODO
                let result = nfd::open_file_dialog(None, None).unwrap_or_else(|e| {
                    panic!(e);
                });
                match result {
                    Response::Okay(file_path) => match reader::read(&file_path) {
                        Ok(s) => {
                            self.ciphertext_content = s;
                            self.update(Message::ResultChanged(String::from(
                                "ReadCipherTextFromFile: Success",
                            )))
                        }
                        Err(why) => {
                            self.update(Message::ResultChanged(format!(
                                "ReadCipherTextFromFile: Error occured: {:?}",
                                why
                            )));
                        }
                    },
                    Response::OkayMultiple(_files) => {
                        self.update(Message::ResultChanged(String::from(
                            "ReadCipherTextFromFile: Not supposed to read from multiple files.",
                        )));
                    }
                    Response::Cancel => {
                        self.update(Message::ResultChanged(String::from(
                            "ReadCipherTextFromFile: User cancelled.",
                        )));
                    }
                }
            }
            Message::WriteCipherTextToFile => {
                //@TODO
                let result = nfd::open_file_dialog(None, None).unwrap_or_else(|e| {
                    panic!(e);
                });
                match result {
                    Response::Okay(file_path) => {
                        match writer::write(&file_path, &self.ciphertext_content) {
                            Ok(_t) => {
                                self.update(Message::ResultChanged(String::from(
                                    "WriteCipherTextToFile: Success",
                                )));
                            }
                            Err(why) => {
                                self.update(Message::ResultChanged(format!(
                                    "WriteCipherTextToFile: Error occured: {:?}",
                                    why
                                )));
                            }
                        }
                    }
                    Response::OkayMultiple(_files) => {
                        self.update(Message::ResultChanged(String::from(
                            "WriteCipherTextToFile: Not supposed to read from multiple files.",
                        )));
                    }
                    Response::Cancel => {
                        self.update(Message::ResultChanged(String::from(
                            "WriteCipherTextToFile: User Canceled.",
                        )));
                    }
                }
            }
        }
    }

    fn view(&mut self) -> Element<Message> {
        let pick_list = PickList::new(
            &mut self.pick_list,
            &Cipher::ALL[..],
            Some(self.selected_cipher),
            Message::CipherSelected,
        );
        let clear_text = TextInput::new(
            &mut self.cleartext,
            "clear text goes here",
            &self.cleartext_content,
            Message::ClearTextChanged,
        );

        let cipher_text = TextInput::new(
            &mut self.ciphertext,
            "clear text goes here",
            &self.ciphertext_content,
            Message::CipherTextChanged,
        );

        let key_text = TextInput::new(&mut self.key, "key", &self.key_content, Message::KeyChanged);

        let encrypt_button = Button::new(&mut self.encryptbutton_state, Text::new("Encrypt"))
            .on_press(Message::Encrypt);
        let decrypt_button = Button::new(&mut self.decryptbutton_state, Text::new("Decrypt"))
            .on_press(Message::Decrypt);
        let button_set = Row::new()
            .padding(30)
            .align_items(Align::Center)
            .push(encrypt_button)
            .push(decrypt_button);
        let result_text = Text::new(self.result.to_string());

        let ciphertext_read_button = Button::new(
            &mut self.ciphertext_read_button_state,
            Text::new("Read from file"),
        )
        .on_press(Message::ReadCipherTextFromFile);
        let ciphertext_write_button = Button::new(
            &mut self.ciphertext_write_button_state,
            Text::new("Write to file"),
        )
        .on_press(Message::WriteCipherTextToFile);
        let cleartext_read_button = Button::new(
            &mut self.cleartext_read_button_state,
            Text::new("Read from file"),
        )
        .on_press(Message::ReadClearTextFromFile);
        let cleartext_write_button = Button::new(
            &mut self.cleartext_write_button_state,
            Text::new("Write to file"),
        )
        .on_press(Message::WriteClearTextToFile);

        let cleartext_button_set = Row::new()
            .padding(30)
            .align_items(Align::Center)
            .push(cleartext_read_button)
            .push(cleartext_write_button);

        let ciphertext_button_set = Row::new()
            .padding(30)
            .align_items(Align::Center)
            .push(ciphertext_read_button)
            .push(ciphertext_write_button);

        Column::new()
            .padding(20)
            .align_items(Align::Center)
            .push(pick_list)
            .push(clear_text)
            .push(key_text)
            .push(cleartext_button_set)
            .push(button_set)
            .push(cipher_text)
            .push(ciphertext_button_set)
            .push(result_text)
            .into()
    }
}

pub fn main() -> iced::Result {
    Counter::run(Settings {
        default_font: Some(include_bytes!("./sarasa-gothic-sc-regular.ttf")),
        ..Settings::default()
    })
}