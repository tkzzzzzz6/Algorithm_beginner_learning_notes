impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let s = directions.as_str();
        let l = s.find(|c| c != 'L');
        let r = s.rfind(|c| c != 'R');

        if l.is_none() || r.is_none(){
            return 0;
        }
        let l = l.unwrap();
        let r = r.unwrap();

        if l > r{
            return 0;
        }
        s[l..=r].chars().filter(|&c| c != 'S').count() as i32 
    }
}
