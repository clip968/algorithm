use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let params: Vec<usize> = input.trim().split_whitespace()
        .map(|x| x.parse().unwrap()).collect();
    let n = params[0];
    let t = params[1] as i64;

    let mut vec = Vec::new();
    for _ in 0..n as usize {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let params: Vec<i64> = input.trim().split_whitespace()
            .map(|x| x.parse().unwrap()).collect();
        vec.push((params[0], params[1]));
    }

    let mut left = 0;
    let mut right = i32::MAX;
    let mut result = -1;

    while left<=right {
        let mid = (left+right)/2;
        if is_valid(mid as i64, t, &vec) {
            result = mid as i64;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    println!("{}", result);

}

fn is_valid(s: i64, t: i64, vec: &Vec<(i64, i64)>) -> bool {
    let mut min_value = 0;
    let mut max_value = 0;

    for &(a, b) in vec {
        let temp_min = a;
        let temp_max = b.min(s);
        if temp_min > temp_max {
            return false;
        }
        min_value += temp_min;
        max_value += temp_max;
    }
    min_value <= t && t <= max_value
}

