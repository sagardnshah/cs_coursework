import java.util.StringTokenizer;

public class Test
{
    public static void main(String[] args)
    {
         StringTokenizer st = new StringTokenizer("Test sentence, please review!!!", ",! ", true);
         while (st.hasMoreTokens())
         {
             System.out.println(st.nextToken());
         }
    }
}