/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 19:42:37
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-31 12:02:08
 * @Description: Implementation of Railfence Cipher
 */
pub fn encrypt(plain_text: &String, fence_key: i32) -> Option<String> {
    let mut line: Vec<String> = Vec::new();
    for _i in 0..fence_key {
        line.push(String::new());
    }

    let _ser = plain_text
        .chars()
        .enumerate()
        .map(|(i, c)| {
            let _current = line.get_mut(i % fence_key as usize).unwrap().push(c);
            c
        })
        .collect::<String>();

    let mut ans: String = String::new();
    for _line in line {
        ans.push_str(_line.trim());
    }
    Some(ans)
}

pub fn decrypt(cipher_text: &String, fence_key: i32) -> Option<String> {
    let string_length = cipher_text.len() as i32;

    let mut line: Vec<String> = Vec::new();
    for _i in 0..=(string_length / fence_key) {
        line.push(String::new());
    }

    let mut chunk_length: Vec<i32> = Vec::new();
    for _i in 1..=fence_key {
        let delta = string_length % fence_key >= _i;
        let delta = if delta == true { 1 } else { 0 };
        chunk_length.push((string_length / fence_key + delta) as i32);
    }

    let mut list = cipher_text.chars();
    for current_chunk in chunk_length {
        for current_offset in 0..current_chunk {
            let ch = list.next().unwrap();
            line.get_mut(current_offset as usize)
                .unwrap()
                .push(ch);
        }
    }

    let mut ans: String = String::new();
    for _line in line {
        ans.push_str(&_line);
    }
    Some(ans)
}
