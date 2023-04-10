impl Solution {
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v: Vec<i32> = Vec::new();
        let mut head = head.as_ref();
        while head != None {
            v.push(head.unwrap().val);
            head = head.unwrap().next.as_ref();
        }
        let n = v.len();
        let mut res: Vec<i32> = vec![0; n];
        let mut stack: Vec<usize> = Vec::new();
        for i in 0..n {
            while !stack.is_empty() && v[stack[stack.len() - 1]] < v[i] {
                res[stack[stack.len() - 1] as usize] = v[i];
                stack.pop();
            }
            stack.push(i);
        }
        res
    }
}