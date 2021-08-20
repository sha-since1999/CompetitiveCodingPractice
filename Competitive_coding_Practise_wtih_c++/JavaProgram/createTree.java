import java.util.*;

class node {
    int data;
    node LNode;
    node RNode;

    public void node( int data) {
        this.data = data;
        LNode = null;
        RNode = null;
   }
}

class createTree {
    
    public static void main(String[] args) {
        int a[] = { 10,5,15,4,6,12,16 };
        node tree = new node();
        tree.data = a[0];
        Queue<node> qu = new LinkedList<>();
        qu.offer(tree.LNode);
        qu.offer(tree.RNode);
        for( int i=1;i<a.length ;i++){
            node newNode = new node();
            newNode.data = a[i];
            node tmp = qu.peek();
            qu.poll();
            tmp= newNode;
            qu.offer(newNode.LNode);
            qu.offer(newNode.RNode);
        }

        Queue<node> qq = new LinkedList<>();
        qq.offer(tree);
        boolean flag = true;
        while (!qq.isEmpty()) {
            node tmp = qq.peek();
            qq.poll();
            if (tmp != null)
                System.out.print(tmp.data + " ");
            if (tmp.LNode != null) {
                qq.offer(tmp.LNode);
                if (tmp.data < tmp.LNode.data)
                    flag = false;
            }
            if (tmp.RNode != null) {
                qq.offer(tmp.RNode);
                if (tmp.data > tmp.RNode.data)
                    flag = false;
            }
        }
        
        if (flag == true)
            System.out.println("this is binary tree");
        else
            System.out.println("none");
            
    }
}