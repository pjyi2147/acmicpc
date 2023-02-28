use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let a: i64 = iter.next().unwrap().parse().unwrap();
    let n = a / 4;
    for _i in 0..n {
        print!("long ");
    }
    print!("int\n");
}