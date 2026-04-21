import java.awt.*;
import java.awt.event.*;

public class GameFrame extends Frame{
    private int frameWidth = 400;
    private int frameHeight = 400;
    Cell[] cells = new Cell[9];
    Label footerText = new Label("X's turn!");

    public GameFrame(String title) {
        super(title);
        this.addWindowListener(new GameFrameWindowListener());
        this.setLayout(new BorderLayout());
        this.setSize(frameWidth, frameHeight);

        Panel gridPanel = new Panel();
        gridPanel.setSize(frameWidth, frameHeight);
        gridPanel.setLayout(new GridLayout(3, 3));
        for(int i = 0; i < 9; i++) {
            this.cells[i] = new Cell(i);
            gridPanel.add(this.cells[i]);
        }

        this.add(gridPanel, BorderLayout.CENTER);

        Panel footer = new Panel();
        footer.setSize(400, 50);
        footer.setLayout(new FlowLayout());
        footer.add(footerText);
        this.add(footer, BorderLayout.SOUTH);
       
        this.setVisible(true);
    }

    public void setFooterText(String text) {
        this.footerText.setText(text);
    }

}

class GameFrameWindowListener implements WindowListener {
    @Override
    public void windowOpened(WindowEvent e) {
    }

    @Override
    public void windowClosing(WindowEvent e) {
        App.game.Exit();
    }

    @Override
    public void windowIconified(WindowEvent e) {
    }

    @Override
    public void windowDeiconified(WindowEvent e) {
    }

    @Override
    public void windowActivated(WindowEvent e) {
    }

    @Override
    public void windowDeactivated(WindowEvent e) {
    }

    @Override
    public void windowClosed(WindowEvent e) {
    }
}
