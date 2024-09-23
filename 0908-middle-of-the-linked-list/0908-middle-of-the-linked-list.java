
class Solution {
    public ListNode middleNode(ListNode head) {
        if(head.next==null)
        {
            return head;
        }
        int t=0;
        ListNode temp=head;
        while(temp.next!=null)
        {
              temp=temp.next;
              t++;
        }
        t=(t+1)/2;
        while(t>0)
        {
            head=head.next;
            t--;
        }
        return head;

    }
}