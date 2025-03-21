use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let temp:Vec<i32> = input.trim().split_whitespace()
        .map(|x| x.parse().unwrap()).collect();

    let m = temp[1] as usize;
    let n = temp[0] as usize;

    let primes = function(m);
    let result: Vec<_> = primes.into_iter().filter(|&x| x >= n).collect();


    for i in &result {
        println!("{}", i);
    }


}

fn function(m:usize) -> Vec<usize>{
    let mut vec:Vec<bool> = vec![true; m+1];
    vec[0] = false;
    vec[1] = false;

    for i in 2..=((m as f64).sqrt() as usize) {
        if vec[i] {
            for j in (i * i..=m).step_by(i) {
                vec[j] = false;
            }
        }
    }

    vec
        .iter()
        .enumerate()
        .filter(|&(_, &prime)| prime)
        .map(|(index, _)| index)
        .collect()

}



