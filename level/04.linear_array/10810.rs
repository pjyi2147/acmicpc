use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: i64 = iter.next().unwrap().parse().unwrap();
    let m: i64 = iter.next().unwrap().parse().unwrap();
    let mut a = vec![0; n as usize];
    for _i in 0..m {
        input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let i: i64 = iter.next().unwrap().parse().unwrap();
        let j: i64 = iter.next().unwrap().parse().unwrap();
        let k: i64 = iter.next().unwrap().parse().unwrap();
        for i in i - 1..j {
            a[i as usize] = k;
        }
    }

    for i in 0..n {
        print!("{} ", a[i as usize]);
    }
}