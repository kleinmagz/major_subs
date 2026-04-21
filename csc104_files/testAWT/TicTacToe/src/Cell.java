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

    @Override
    public void actionPerformed(ActionEvent e) {
        if(App.game.MarkGrid(cell.index)) {
            cell.setLabel(App.game.getCurrentTurn() == Player.X ? "X" : "O");
            App.game.CheckWin();
            App.game.switchTurn();
        }
    }
}
