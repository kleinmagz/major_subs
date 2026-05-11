import java.awt.*;
import java.awt.event.*;

public class Cell extends Button {
    public int index;

    Cell(int index) {
        this.index = index;
        this.setLabel(" ");
        this.addActionListener(new CellActionListener(this));
    }

}

class CellActionListener implements ActionListener {
    Cell cell;

    public CellActionListener(Cell cell) {
        this.cell = cell;
    }

   
    public void actionPerformed(ActionEvent e) {
        if(App.game.isGameOver || App.game.isDraw) {
            App.game.resetGame();
            return;
        }
        if(!App.game.isGameOver){
            if(App.game.MarkGrid(cell.index)) {
                cell.setLabel(App.game.getCurrentTurn() == Player.X ? "X" : "O");
               App.game.CheckWin();
                if (App.game.isGameOver) {
                    App.game.displayWinner();
                } 
                else if (App.game.isDraw) {
                    App.game.displayDraw();
                }else {
                    App.game.switchTurn();
                    App.game.displayTurn();
                }
            }
        } 
        else {
            cell.removeActionListener(this);
            App.game.displayWinner();
        }
    }
}
