/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-17 16:37:37
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-04-01 11:25:38
 * @Description: Binary crate of Railfence Cipher
 */
use clap::Clap;

extern crate hw01;
use crate::hw01::railfence;
use crate::hw01::reader;
use crate::hw01::writer;

#[derive(Clap)]
#[clap(version = "1.0", author = "Beacon Zhang <beacon1096@beacoworks.xyz>")]
struct Opts {
    /// Sets an input file. If both content and input were not provided, stdin will be used
    #[clap(short, long)]
    input: Option<String>,
    /// Sets an output file. If not provided, stdout will be used
    #[clap(short, long)]
    output: Option<String>,
    /// Select a operating mode. Could be 'e' for encrypting or 'd' for decrypting
    mode: char,
    /// Key used for Railfence Cipher
    key: i32,
    /// Clear text to be encrypted, or cipher text to be decrypted
    content: Option<String>,
    /// Level of verbosity
    #[clap(short, long, parse(from_occurrences))]
    _verbose: i32,
}

fn main() {
    let opts: Opts = Opts::parse();

    let content = if let Some(path) = opts.input {
        match reader::read(&path) {
            Ok(t) => t,
            Err(x) => {
                panic!("{}", x);
            }
        }
    } else {
        opts.content.unwrap()
    };

    let ans = match opts.mode {
        'e' => railfence::encrypt(&content.to_string(), opts.key),
        'd' => railfence::decrypt(&content.to_string(), opts.key),
        _ => Some(
            "Error: wrong mode provided.\nAvailable:  e   - encrypt\n            d   - decrypt"
                .to_string(),
        ),
    };

    let ans = match ans {
        Some(t) => t,
        None => "Error: invalid parameters provided.".to_string(),
    };

    match opts.output {
        Some(path) => {
            if let Err(e) = writer::write(&path, &ans) {
                panic!("{}", e);
            }
        }
        None => {
            println!("{}", ans);
        }
    };
}
