import java.awt.*;
import javax.swing.*;

public class EspiralQuadratico extends JPanel{
   
    // Autor: João Matheus Santos Assis
   
    public void paintComponent( Graphics g){
        super.paintComponent(g);
       
        int width = getWidth();
        int height = getHeight();
       
        for (int i=0; i<30; ++i){
           
            g.drawLine(width/2+10*i,     height/2-10*i,         width/2+10*i,     height/2+10*(i+1));
            g.drawLine(width/2+10*i,     height/2+10*(i+1), width/2-10*(i+1), height/2+10*(i+1));
            g.drawLine(width/2-10*(i+1), height/2+10*(i+1), width/2-10*(i+1), height/2-10*(i+1));
            g.drawLine(width/2-10*(i+1), height/2-10*(i+1), width/2+10*(i+1), height/2-10*(i+1));
           
          
        }
       
    }
   
    public static void main( String [] args){
        EspiralQuadratico importacao = new EspiralQuadratico();
        JFrame application = new JFrame("Espiral Quadrático");
        application.add(importacao);
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        application.setSize(900,700);
        application.setVisible(true);
    }
}
