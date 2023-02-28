use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf
        .split_whitespace()
        .map(|s| s.parse::<usize>().unwrap());
    let mut input = || input.next().unwrap();

    let (n, m) = (input(), input());
    let mut balls : Vec<_> = (1..=n).collect();

    for (i, j) in (0..m).map(|_| (input() - 1, input() - 1)) {
        let i : i32 = i as i32;
        let j : i32 = j as i32;
        let k : i32 = (j - i + 1) / 2;
        for os in 0..k {
            balls.swap((i + os).try_into().unwrap(), (j - os).try_into().unwrap());
        }
    }

    for ball in balls {
        print!("{ball} ");
    }
}