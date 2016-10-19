import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

public class SimpleFrame extends JFrame{
		JPanel painel;
		JLabel texto;
		JButton but, but2, but3, but4;

	public SimpleFrame() { // cria um quadro, "frame", com tudo dentro
		super("Swing Application");
		painel = new JPanel();
		texto = new JLabel("Number of button clicks: 0");
		but = new JButton("I'm a swing button");
		but2 = new JButton("Other button");
		but3 = new JButton("One more button");
		but4 = new JButton("Last button");
		but.addActionListener(this);
		but2.addActionListener(this);
		but3.addActionListener(this);
		but4.addActionListener(this);
		painel.setLayout(new BorderLayout(3,3));
		painel.add(but,BorderLayout.NORTH);
		painel.add(but2,BorderLayout.SOUTH);
		painel.add(but3,BorderLayout.WEST);
		painel.add(but4,BorderLayout.EAST);
		painel.add(texto,BorderLayou.CENTER);
		getContentPane().add(painel);
	}

		// método de ouvinte, para tratar os eventos gerados ao clicar um botão
		public void actionPerformed(ActionEvent evt){
				Object source = evt.getSource();
		// A variável "color" precisa ter um valor inicial
		// pois todas as decisões poderiam falhar, em teoria.
			if (source == but) {
				contB1++;
				texto.setText("Button 1 clicked:" + contB1);
			}
			if (source == but2) {
				contB2++;
				texto.setText("Button 2 clicked:" + contB2);
			}
			if (source == but3) {
				contB3++;
				texto.setText("Button 3 clicked:" + contB3);
			}
			if (source == but4) {
				contB4++;
				texto.setText("Button 4 clicked:" + contB4);
			}
		}

	public static void main (String args[]) {
		SimpleFrame f = new SimpleFrame();
		f.pack();
		f.setSize(400, 200);
		f.setVisible(true);
	}
}
