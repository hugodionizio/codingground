import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

public class InterfaceEArquivo extends JFrame implements ActionListener {
	private JButton gravar, limparTela, ler;
	private JTextArea texto;
	private JTextField nomeArq;
	private JPanel painelBotoes, painelTexto;
	private File arquivo;

	public InterfaceEArquivo() {
		super("GUI e Arquivo");
		gravar = new JButton("Gravar");
		limparTela = new JButton("Limpar Tela");
		ler = new JButton("Ler");
		texto = new JTextArea();
		texto.setPreferredSize(new Dimension(70, 70));
		nomeArq = new JTextField();
		painelBotoes = new JPanel();
		painelTexto = new JPanel();

		gravar.addActionListener(this);
		limparTela.addActionListener(this);
		ler.addActionListener(this);

		painelBotoes.setLayout(new BoxLayout(painelBotoes, BoxLayout.Y_AXIS));
		painelBotoes.add(gravar);
		painelBotoes.add(limparTela);
		painelBotoes.add(ler);

		painelTexto.setLayout(new BorderLayout());
		painelTexto.add(nomeArq, BorderLayout.NORTH);
		painelTexto.add(texto, BorderLayout.CENTER);

		getContentPane().add(painelBotoes, BorderLayout.WEST);
		getContentPane().add(painelTexto, BorderLayout.CENTER);
	}

	public void actionPerformed(ActionEvent e) {
		Object but = e.getSource();

		if (but == limparTela) {
			texto.setText("");
			nomeArq.setText("");
		}
		if (but == gravar) {
			arquivo = new File(nomeArq.getText());
			escrever(arquivo, texto.getText());
		}
		if (but == ler) {
			arquivo = new File(nomeArq.getText());
			String lida = ler(arquivo);
			texto.setText(lida);
		}
	}

	public void escrever (File arq, String t) {
		try {
			FileWriter writer = new FileWriter(arq);
			PrintWriter saida = new PrintWriter(writer);
			saida.print(t);	
			saida.close();
			writer.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	public String ler(File arq) {
		String t = "";
		try {
			FileReader reader = new FileReader(arquivo);
			BufferedReader leitor = new BufferedReader(reader);
			String linha = "";
			while ((linha = leitor.readLine()) != null)
				t = t + linha + "\n";
			leitor.close();
			reader.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {return t;}
	}

	public static void main (String args[]) {
		InterfaceEArquivo e = new InterfaceEArquivo();
		e.pack();
		e.setSize(400, 200);
		e.setVisible(true);
	}
}
