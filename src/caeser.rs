/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-21 20:48:31
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-29 20:55:21
 * @Description: Implementation of Caeser Cipher
 */
pub fn encrypt(clear_text: &String, offset: i32) -> Option<String> {
    let offset: u8 = (offset % 26) as u8;
    let mut watchdog_bark = 0;
    let ans: String = clear_text
        .chars()
        .enumerate()
        .map(|(_i, c)| -> char {
            if !char_valid(c) {
                watchdog_bark = 1;
                ' '
            } else {
                if let Some(g) = transform(c, offset) {
                    g
                } else {
                    panic!("[Caeser]Inacceptable char encountered while encrypting.")
                }
            }
        })
        .collect();
    if watchdog_bark != 1 {
        Some(ans)
    } else {
        None
    }
}
pub fn decrypt(cipher_text: &String, offset: i32) -> Option<String> {
    let offset: u8 = (offset % 26) as u8;
    let mut watchdog_bark = 0;
    let ans: String = cipher_text
        .chars()
        .enumerate()
        .map(|(_i, c)| -> char {
            if !char_valid(c) {
                watchdog_bark = 1;
                ' '
            } else {
                if let Some(g) = detransform(c, offset) {
                    g
                } else {
                    panic!("[Caeser]Inacceptable char encountered while encrypting.")
                }
            }
        })
        .collect();
    if watchdog_bark == 1 {
        None
    } else {
        Some(ans)
    }
}
fn char_valid(c: char) -> bool {
    c.is_ascii_alphabetic() || c.is_ascii_whitespace()
}
fn transform(c: char, offset: u8) -> Option<char> {
    if c.is_whitespace() {
        Some(' ')
    } else if c.is_ascii_lowercase() {
        Some(((c as u8 - 'a' as u8 + offset) % 26 + 'a' as u8) as char)
    } else if c.is_ascii_uppercase() {
        Some(((c as u8 - 'A' as u8 + offset) % 26 + 'A' as u8) as char)
    } else {
        None
    }
}
fn detransform(c: char, offset: u8) -> Option<char> {
    if c.is_whitespace() {
        Some(' ')
    } else if c.is_ascii_lowercase() {
        Some(((c as u8 - 'a' as u8 + 26 - offset) % 26 + 'a' as u8) as char)
    } else if c.is_ascii_uppercase() {
        Some(((c as u8 - 'A' as u8 + 26 - offset) % 26 + 'A' as u8) as char)
    } else {
        None
    }
}
