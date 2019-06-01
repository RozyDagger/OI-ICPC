/***************************************************
A Knight on the Chess board can make 8 valid moves. We can say that it either moves two squares sideways and then one square up or down, or two squares up or down, and then one square sideways.

Unlike Chess, the game we're playing is based on chance. The Knight chooses to make a move in a uniformly random pattern(i.e. each of the 8 valid moves are equally likely). Then, a Dice is rolled to tell the Knight how many moves to make. Will the Knight stay on the board after making the number of moves rolled by the Dice?

You are given the initial x and y coordinate of the Knight, and K is the number rolled by the Dice. Calculate the probability that the Knight will stay on the board after K moves. Once the Knight is off the board, it cannot come back.

Input Format

A line containing the number of moves K, the initial x coordinate of the Knight x and the initial y coordinate of the Knight y.

Constraints

1 <= K <= 6
0 <= x < 8
0 <= y < 8
Output Format

The probability of the Knight remaining on the board, with a precision of 4 decimal places.

Sample Input 0

1 7 3
Sample Output 0

0.5000
Explanation 0

The Knight can make 4 valid moves to (6, 5), (6, 1), (5, 4), (5, 2). Since the total no. of moves the Knight could make is 8, the answer is 4/8 = 0.5
***************************************************/
import java.util.Scanner;
public class Solution {
    static int dx[]={1, 2, 2, 1, -1, -2, -2, -1}, dy[]={2, 1, -1, -2, -2, -1, 1, 2};
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int K= in.nextInt();
        int x=in.nextInt();
        int y=in.nextInt();
        double dp[][][] = new double[K+1][8][8];
        for (int i = 0;i<8;++i) for(int j=0;j<8;++j) dp[0][i][j]=1;
        for(int i=1;i<= K;++i)
            for(int j=0;j<8;++j)
                for (int k=0;k<8;++k){
                    dp[i][j][k]=0.0;
                    for (int l=0;l<8;++l){
                        int a =j+dx[l], b=k+dy[l];
                        if(a>=0&&a<8&&b>=0&&b<8) dp[i][j][k]+=dp[i-1][a][b]/8.0;
                    }
                }
        double rst=(double)Math.round(dp[K][x][y]*10000d)/10000d;
        System.out.println(rst);
    }
}
