use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let t: u8 = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: u8 = it.next().unwrap().parse().unwrap();

        let mut sum: i64 = 0;

        for _ in 0..n {
            sum += it.next().unwrap().parse::<i64>().unwrap();
        }

        if sum % 4 == 0 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
