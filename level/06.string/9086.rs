use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let n : usize = input.next().unwrap().parse().unwrap();

    for _i in 0..n {
        let st = String::from(input.next().unwrap());
        print!("{}{}\n", st.chars().nth(0).unwrap(), st.chars().last().unwrap());
    }
}