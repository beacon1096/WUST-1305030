/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-17 19:54:32
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-30 16:13:56
 * @Description: Binary crate of Caeser Cipher
 */
use clap::Clap;

extern crate hw01;
use crate::hw01::caeser;
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
    /// Key used for Caeser Cipher
    key: i32,
    /// Clear text to be encrypted, or cipher text to be decrypted
    content: Option<String>,
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

    let ans = match opts.mode{
        'e' => {caeser::encrypt(&content, opts.key)}
        'd' => {caeser::decrypt(&content, opts.key)}
         _  => {Some("Error: wrong operating mode provided.\nAvailable:  e   - encrypt\n            d   - decrypt\nRun again with -h flag to see argument details.".to_string())} 
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
