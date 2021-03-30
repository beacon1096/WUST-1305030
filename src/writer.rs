/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 20:46:07
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-30 16:15:12
 * @Description: Writer snippet
 */
use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

pub fn write(file_path: &String, content: &String) -> Result<bool, std::io::Error> {
    let path = Path::new(file_path);
    //let display = path.display();

    let mut file = match File::create(&path) {
        Err(why) => {
            return Err(why);
        }
        Ok(file) => file,
    };

    if let Err(why) = file.write_all(content.as_bytes()) {
        return Err(why);
    }

    Ok(true)
}
