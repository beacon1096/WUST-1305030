/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 19:44:17
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-31 12:44:01
 * @Description: Implementation of Caeser Cipher
 */
use std::collections::HashMap;
use std::hash::Hash;

#[derive(Eq, Hash, PartialEq)]
struct Coordinate(i32, i32);

impl Coordinate {
    fn to_string(&self) -> String {
        let a = self.0.to_string();
        let b = self.1.to_string();
        a + &b
    }
}

pub fn encrypt(clear_text: &String) -> Option<String> {
    let clear_text = clear_text.to_ascii_lowercase();
    let mut map: HashMap<char, Coordinate> = HashMap::new();
    for i in 0..26 {
        let delta: i32 = if i >= ('j' as u8 - 'a' as u8) as i32 {
            -1
        } else {
            0
        };
        let offset = i + delta;
        let coord = Coordinate(offset / 5 + 1, offset % 5 + 1);
        map.insert(('a' as u8 + i as u8) as char, coord);
    }
    let mut watchdog_bark = 0;
    let ans: String = clear_text
        .chars()
        .enumerate()
        .map(|(_i, c)| match map.get(&c) {
            Some(t) => t.to_string(),
            None => {
                if c.is_ascii_whitespace() {
                    "".to_string()
                }
                else {
                    watchdog_bark = 1;
                    "".to_string()
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

pub fn decrypt(cipher_text: &String) -> Option<String> {
    let mut map: HashMap<Coordinate, String> = HashMap::new();
    for i in 0..25 {
        let coord = Coordinate(i / 5 + 1, i % 5 + 1);
        let delta = if i >= ('j' as u8 - 'a' as u8) as i32 {
            true
        } else {
            false
        };
        let delta = if delta { 1 } else { 0 };
        map.insert(
            coord,
            (('a' as u8 + i as u8 + delta as u8) as char).to_string(),
        );
    }
    map.insert(Coordinate(2, 4), "[i||j]".to_string());
    let sequence = cipher_text
        .replace(" ", "")
        .chars()
        .enumerate()
        .flat_map(|(i, c)| {
            if i != 0 && i % 2 == 0 {
                Some(' ')
            } else {
                None
            }
            .into_iter()
            .chain(std::iter::once(c))
        })
        .collect::<String>();
    let sequence = sequence.split(' ');
    let mut ans = String::new();
    for current in sequence {
        let current = current.parse::<i32>();
        let current = match current {
            Ok(x) => x,
            Err(_e) => -1,
        };
        if current == -1 {
            return None;
        }
        let coord = Coordinate(current / 10, current % 10);
        if map.get(&coord).is_none() {
            return None;
        }
        ans.push_str(map[&coord].as_str());
    }
    Some(ans)
}
