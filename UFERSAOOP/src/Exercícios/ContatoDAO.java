

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;

import javax.management.RuntimeErrorException;

import beans.ConnectionFactory;
import beans.Contato;

import com.mysql.jdbc.PreparedStatement;

public class ContatoDAO extends Contato {
	// a conexão com o banco de dados
	private Connection connection;
	
	public ContatoDAO() {
		this.connection = new ConnectionFactory().getConnection();
	}

	public void adiciona(Contato contato) {
		String sql = "insert into contatos " +
				"(nome, email, endereco, dataNascimento)" +
				"values  (?, ?, ?, ?)";
		try {
			// prepared statement para inserção
			PreparedStatement stmt = con.prepareStatement(sql);
			
			// seta os valores
			stmt.setString(1, contato.getNome());
			stmt.setString(2, contato.getEmail());
			stmt.setString(3, contato.getEndereco());
			stmt.setDate(4, new Date(
					contato.getDataNascimento().getTimeInMillis()));
		}
	}
	
	public void buscar(Contato contato) {
		PreparedStatement stmt = this.connection
				.prepareStatement("select * from contatos");
		ResultSet rs = stmt.executeQuery();
		
		Lista<Contato> contatos = new ArrayList<Contato>();
		
		while (rs.next()) {
			// criando o objeto Contato
			Contato.contato = new Contato();
			contato.setNome(rs.getString("nome"));
			contato.setEmail(rs.getString("email"));
			contato.setEndereco(rs.getString("endereco"));
			
			// montando a data através do Calendar
			Calendar data = Calendar.getInstance();
			data.setTime(rs.getDate("dataNascimento"));
			contato.setDataNascimento(data);
			
			// adicionando o objeto à Lista
			contatos.add(contato);
		}
		
		rs.close();
		stmt.close();
		
		return contatos;
	}
	
	public void altera(Contato contato) {
		String sql = "update contatos set nome=?, email=?, endereco=?," +
					"dataNascimento=? where id=?";
		try {
			PreparedStatement stmt = connection.prepareStatement(sql);
			stmt.setString(1, contato.getNome());
			stmt.setString(2, contato.getEmail());
			stmt.setString(3, contato.getEndereco());
			stmt.setDate(4, new Date(contato.getDataNascimento().getTimeInMillis()));
			stmt.setLong(5, contato.getId());
			stmt.execute();
			stmt.close();
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	public void remover(Contato contato) {
		try {
			PreparedStatement stmt = connection.prepareStatement("delete" + 
					"from contatos where id=?");
			stmt.setLong(1, contato.getId());
			stmt.execute();
			stmt.close();
		} catch (SQLException e) {
			throw new RuntimeErrorException(e);
		}
	}
}
