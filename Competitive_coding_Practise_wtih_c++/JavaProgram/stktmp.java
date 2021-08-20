import java.util.*;
class stktmp {

    static class stk {
         static Queue<Integer>  q1 = new LinkedList<>();
         static Queue<Integer> q2 = new LinkedList<>();

         static int curr_size;
         stk() {
             curr_size = 0;
         }

         public static void push( int key){
            q2.offer(key);
            curr_size++;
            while(!q1.isEmpty()){
                q2.offer(q1.peek());
                q1.poll();
            }
            
            // swap queues
            Queue<Integer> q =q1;
            q1= q2;
            q2= q;

        }
        
         public static void pop() {
             if (q1.isEmpty())
                 return;
            q1.remove();
             curr_size--;

         }

         public static Integer size() {
             return curr_size;
         }

         public static Integer peek() {
             if (q1.isEmpty())
                return -1;
            return q1.peek();

        }
    
    }

     public static void main(String[] args) {
         stk st = new stk();
         st.push(1);
         st.push(2);
         st.push(3);
         st.push(4);
         System.out.println(st.peek());
         st.pop();
         System.out.println(st.peek());
         st.pop();
         System.out.println( "stack size: " + st.size());
         System.out.println(st.peek());
         st.pop();
         System.out.println(st.peek());
         st.pop();
         


     }

}