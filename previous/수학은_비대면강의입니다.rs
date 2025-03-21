use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let param: Vec<i64> = input.trim().split_whitespace()
        .map(|x| x.parse().unwrap()).collect();

    let a = param[0];
    let b = param[1];
    let c = param[2];
    let d = param[3];
    let e = param[4];
    let f = param[5];

    for x in -999..=999{
        for y in -999..=999{
            if x*a + b*y == c && x*d + y*e == f{
                println!("{} {}", x, y);
                break;
            }
        }
    }

}



