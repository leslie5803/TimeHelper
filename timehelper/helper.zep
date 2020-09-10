
namespace TimeHelper;

class Helper {

    public static function say(){
        echo "hello world!";
    }
    
    public function before(int! sec)-> string|bool {
        if sec > time() || sec < 0 {
            return false;
        }
        
        int diff;
        let diff = time() - sec;
        if diff <= 60 {
            return diff . "秒前";
        }

        if diff > 60 && diff < 3600 {
            return this->getMin(diff);
        }

        if diff >= 3600 && diff < 86400 {
            return this->getHour(diff);
        }

        if diff >= 86400 && diff < 2592000 {
            return this->getDay(diff);
        }

        if diff >= 2592000 && diff < 2592000 * 12 {
            return this->getMonth(diff);
        }
        
        return this->getYear(diff);
    }

    private function getMin(int! sec)-> string{
            if sec === 0 {
                return "";
            }

            int min = intval(sec / 60);
            let sec = sec % 60;
            if sec > 0 {
                return min . "分" . sec . "秒前";
            }

            return min . "分前";
    }

    private function getHour(int! sec)-> string {
            int hour = intval(sec / 3600);
            int diff = sec % 3600;
            var min = this->getMin(diff);

            if strlen(min) {
                return hour . "小时" . min;
            }

            return hour . "小时前";
    }

    private function getDay(int! sec)->string {
            int day = intval(sec / 86400);

            return day . "天前";
    }

    private function getMonth(int! sec)-> string {
            int month = intval(sec / 2592000);

            return month . "月前";
    }

    private function getYear(int! sec) -> string {
            int year = intval(sec / 2592000 / 365);

            return year . "年前";
    }
}
