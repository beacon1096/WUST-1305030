/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 20:46:11
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-30 16:15:03
 * @Description: Reader snippet
 */
use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

pub fn read(file_path: &String) -> Result<String, std::io::Error> {
    let path = Path::new(file_path);
    //let display = path.display();

    let mut file = match File::open(&path) {
        Err(why) => {
            return Err(why);
        }
        Ok(file) => file,
    };

    let mut s = String::new();
    if let Err(why) = file.read_to_string(&mut s) {
        return Err(why);
    }

    return Ok(s);
}
