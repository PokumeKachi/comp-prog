use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();
    let mut next = || it.next().unwrap().parse().unwrap();

    let t: u16 = next();

    for _ in 0..t {
        let n: u32 = it.next().unwrap().parse().unwrap();

        let p: Vec<u32> = vec![0; n];

        for i in 1..n {
            p[i] = it.next().unwrap().parse().unwrap() - 1;
        }

        let m: u32 = it.next().unwrap().parse().unwrap()

        let a: Vec<u32> = vec![0; m];

        for i in 0..m {
            a[i] = it.next().unwrap().parse().unwrap() - 1;
        }
    }

    println!("{}", t);
}
