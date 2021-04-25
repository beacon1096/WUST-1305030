/*
 * @Author: Beacon Zhang
 * @Date: 2021-03-22 19:14:26
 * @LastEditors: Beacon Zhang
 * @LastEditTime: 2021-04-01 11:36:08
 * @Description: Root of Lib Crate
 */
pub mod caeser;
pub mod polybius;
pub mod railfence;

pub mod reader;
pub mod writer;

mod test {
    #[test]
    fn caeser() {
        let t = (2 + 0 + 2 + 0 + 0 + 3 + 1 + 9 + 1 + 0 + 5 + 4) % 26;
        let t = if t == 0 { 3 } else { t };
        assert_eq!(
            super::caeser::encrypt(&String::from("Zhang Bocheng"), t).unwrap(),
            "Aiboh Cpdifoh"
        );
        assert_eq!(
            super::caeser::decrypt(&"Aiboh Cpdifoh".to_string(), t).unwrap(),
            "Zhang Bocheng"
        )
    }
    /// Letter Capital is lost during encryption process
    #[test]
    fn polybius() {
        assert_eq!(
            super::polybius::encrypt(&String::from("ZhangBocheng")).unwrap(),
            "552311332212341323153322"
        );
        assert_eq!(
            super::polybius::decrypt(&"552311332212341323153322".to_string()).unwrap(),
            "zhangbocheng"
        )
    }
    #[test]
    fn railfence() {
        let t= ((0.0 + 5.0 + 4.0) / 3.0 as f64).ceil() as i32;
        assert_eq!(
            super::railfence::encrypt(&String::from("Zhang Bocheng"), t).unwrap(),
            "ZnBhghgoea cn"
        );
        assert_eq!(
            super::railfence::decrypt(&"ZnBhghgoea cn".to_string(), t).unwrap(),
            "Zhang Bocheng"
        )
    }
}
