/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 19:14:26
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-03-30 15:54:43
 * @Description: Root of Lib Crate
 */
pub mod caeser;
pub mod polybius;
pub mod railfence;

pub mod reader;
pub mod writer;
//pub use crate::caeser;
mod test {
    #[test]
    fn caeser() {
        let t = (2 + 0 + 2 + 0 + 0 + 3 + 1 + 9 + 1 + 0 + 5 + 4) % 26;
        let t = if t == 0 { 3 } else { t };
        assert_eq!(
            super::caeser::encrypt(&String::from("Zhang Bocheng"), t).unwrap(),
            "233"
        );
    }
}
