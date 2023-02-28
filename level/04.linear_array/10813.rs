use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: i32 = iter.next().unwrap().parse().unwrap();
    let m: i32 = iter.next().unwrap().parse().unwrap();
    let mut v = vec![0; n as usize];
    for i in 0..n {
        v[i as usize] = i + 1;
    }

    for _i in 0..m {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        v.swap((a - 1).try_into().unwrap(), (b - 1).try_into().unwrap());
    }

    for i in 0..n {
        print!("{} ", v[i as usize]);
    }
    println!();
}