use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let params: Vec<usize> = input.trim().split_whitespace()
        .map(|x| x.parse().unwrap()).collect();
    let n = params[0];
    let m = params[1];

    let result = to_base36(n as i64, m as i64);
    println!("{}", result);

}

fn to_base36(mut n: i64, m: i64) -> String {
    let mut result = String::new();
    while n > 0 {
        let digit = n % m;
        let number = if digit < 10 {
            (digit as u8 + b'0') as char 
        } else{
            (digit as u8 - 10 + b'A') as char
        };
        result.push(number);
        n /= m;
    }
    result.chars().rev().collect()
}

