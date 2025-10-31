use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let trimmed = input.trim();

    println!("{}", if is_palindrome(&trimmed) { "1" } else { "0" });

}

fn is_palindrome(str: &str) -> bool {
    let reverse = str.chars().rev().collect::<String>();
    str == reverse
}
