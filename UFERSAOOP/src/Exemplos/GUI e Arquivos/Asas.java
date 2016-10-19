 /* Programa que ensina como controlar a janela (JFrame), mostrando como se botar título, desativar o maximizar, abrir o programa no meio da tela, torna-lo visível e obter a largura e a altura do monitor do usuário.*/

// Autor: João Matheus Santos Assis
import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.JFrame;
public class Asas{
   
   public static void main(String [] args){
       
        // Cria o JFrame e define o nome na barra de título
       JFrame f = new JFrame("Título");
       f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       f.setVisible(true);
      
            // Obtém as dimensões da tela
            Toolkit Kit = Toolkit.getDefaultToolkit();
            Dimension TamalhoDeTela = Kit.getScreenSize();
            // Altura recebe o valor da altura do monitor do usuário
             int Altura  = TamalhoDeTela.height;
            // Largura recebe o valor da largura do monitor
             int Largura = TamalhoDeTela.width;       
            f.setSize(Largura/2,Altura/2);
            // Exibe a janela no meio da tela
            f.setLocationRelativeTo(null);
   }   
}
