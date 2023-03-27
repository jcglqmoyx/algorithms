#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        match head {
            None => None,
            Some(mut node) => {
                let right = Self::remove_elements(node.next, val);
                if node.val == val {
                    right
                } else {
                    node.next = right;
                    Some(node)
                }
            }
        }
    }
}