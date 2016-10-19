import javax.swing.JFrame;
import javax.swing.JTextArea;

public class Formulario extends JFrame{
	private JMenuBar menubar = new JMenuBar();  
	private JMenu arquivo = new JMenu("Arquivo");
	private JMenu ajuda = new JMenu("Ajuda");

	private void montaJanela(){  
		this.getContentPane().add(texto);  
	}  

/*
Título: Formulário
Botões: anterior, próximo, fechar

Menus
	Arquivo: Iniciar pesquisa, Carregar pesquisa, Sair
	Ajuda: Sobre (Hugo Dionizio Santos, Programação Orientada a Objetos)

Abas
	Painel 1
		setNome() {
			this. = ;
			}
		void setMatrícula() {
			this. = ;
			}
		void setSexo: Masculino, Feminino() {
			this. = ;
			}
		void setData de nascimento() {
			this. = ;
			}
		void setCurso() {
			this. = ;
			}
		void setInicio do curso: 2008, 2009, 2010() {
			this. = ;
			}

		getNome() {
			return ;
			}
		getMatrícula() {
			return ;
			}
		getSexo: Masculino, Feminino() {
			return ;
			}
		getData de nascimento() {
			return ;
			}
		getCurso() {
			return ;
			}
		getInicio do curso: 2008, 2009, 2010() {
			return ;
			}
		Botões: Próximo
	Painel 2
		Quadros: QuadroEsquerdo, QuadroDireito
		Álgebra Linear
		Algoritmos
		Análise de Algoritmos
		Banco de Dados
		Compiladores
		Cálculo I
		Cálculo II
		Cálculo III
		Cálculo Numérico
		Engenharia de Software
		Botões: Copiar, Próximo
	Painel 3
		Escreva sobre alguns dos motivos que te levaram a escolher o curso:
		Aqui deverá ser utilizado um componente que permita a escrita de textos longos
		Botôes: Finalizar
	Relatório: Dados
	Nome: Programação II
	Sexo: Masculino
	Data de nascimento: 1 de janeiro de 2010
	Curso: Ciência da Computação
	Ano de início: 2008

	Disciplinas escolhidas como importantes no curso
	Algoritmos
	Banco de Dados
	Cálulo I

	Alguns dos motivos por ter escolhido o curso
		Aqui deverá ser utilizado um componente que permita a escrita de textos longos

	Satisfação com o curso: 90%
	Linguagem que gostaria de aprender
		JME
		Python
		Ruby
	Carregar pesquisa
*/

	private JTextArea texto = new JTextArea();

	public Formulario(){
		super("Formulário");
		this.montaJanela();
	}

	public static void main(String[] args){
	       	Formulario janela = new Formulario();
		janela.setVisible(true);
		janela.setSize(640,480);
	} 
}


