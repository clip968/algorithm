use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let params: Vec<usize> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let n = params[0];
    let m = params[1];

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut vec: Vec<i64> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    vec.sort();
    let mut low = 0;
    let mut high = *vec.last().unwrap();
    let mut r = 0;
    while low <= high {
        let mut result = 0;
        let mid = (low + high) / 2;
        for i in &vec {
            if *i > mid {
                result += *i - mid;
            }
        }
        if result as usize >= m {
            r = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    println!("{}", r);


}