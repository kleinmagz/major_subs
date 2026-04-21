
enum Player {
    X,
    O
}

public class Game {
    private GameFrame frame;

    private Player currentTurn = Player.X;
    private Player[] gridState = new Player[9];

    static int[][] winningCombinations = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    public Game(String title) {
        this.frame = new GameFrame(title);
    }

    Player getCurrentTurn() {
        return this.currentTurn;
    }

    void switchTurn() {
        this.currentTurn = (this.currentTurn == Player.X) ? Player.O : Player.X;
        this.frame.setFooterText(this.currentTurn + "'s turn!");
    }

    public Boolean MarkGrid(int index) {
        if(this.gridState[index] != null) {
            return false;
        }
        this.gridState[index] = this.currentTurn;
        return true;
    }

    public void CheckWin() {
        
        for(int i = 0; i < winningCombinations.length; i++) {
            if(this.gridState[winningCombinations[i][0]] == currentTurn &&
               this.gridState[winningCombinations[i][1]] == currentTurn &&
               this.gridState[winningCombinations[i][2]] == currentTurn 
            ) {
                this.frame.setFooterText(currentTurn + " wins!");
                System.out.println(currentTurn + " wins!");
            
            }
        }
        int count = 0;
        for(int i = 0; i < 9; i++) {
            if(this.gridState[i] != null)
                count++;
        }

        if(count == 9) {
            this.frame.setFooterText("Draw!");

        }
    }

    public void Exit() {
        this.frame.dispose();
    }
}
