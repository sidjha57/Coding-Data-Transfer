import java.util.Random;
public class RockPaperScissorGame {
    public static void main(String[] args) {
        int times = 5, score_a = 0, score_b = 0;

        Random random = new Random();


        while (times > 0) {
            times--;
            int a = random.nextInt()%3;
            int b = random.nextInt()%3;
            /*
                0 is rock
                1 is paper
                2 is scissor
             */
            if (a == b) continue;
            if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0) ) {
                score_b++;
            } else {
                score_a++;
            }
        }

        if (score_a > score_b)
            System.out.println("Player 1 Win, Player1 score " + score_a + " Player2 score " + score_b);
        else if (score_b > score_a)
            System.out.println("Player 2 Win, Player1 score " + score_a + " Player2 score " + score_b);
        else
            System.out.println("Tie, Player1 score " + score_a + " Player2 score " + score_b);

    }
}
