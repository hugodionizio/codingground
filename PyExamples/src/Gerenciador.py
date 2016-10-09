#coding: utf-8
import pygtk
import gtk

titulo = "Gerador de funções"

pygtk.require('2.0') #versão recomendada

class j_princ: #criamos a classe da janela
   
   def __init__(self): #função principal
      self.janela = gtk.Window() #janela
      self.janela.set_title(titulo) #título
      self.janela.set_border_width(int(len(titulo)*1.6)) #largura da borda
      self.janela.connect('destroy', self.fechar, self.janela) #envento de sair
      
      self.conteudo = gtk.VBox(False, 1) #um VBox e dois HBox
      self.msgBox = gtk.HBox(False, 2)
      self.boxButton = gtk.HBox(False, 1)
      
      self.msgBox.set_border_width(8) #borda dos HBox
      self.boxButton.set_border_width(8)
      
      self.rotulo1 = gtk.Label("Digite a mensagem a ser enviada:") #rótulo, para evitar ser impresso no terminal
      self.mensagem = gtk.Entry() #caixa de texto
      self.btnEnviar = gtk.Button("Enviar") #botão Enviar
      self.btnEnviar.connect('clicked', self.ev_Enviar, self.mensagem) #evento para botão Enviar
      self.btnSair = gtk.Button("Sair") #botão Sair
      self.btnSair.connect('clicked', lambda w: self.janela.destroy()) #evento para botão Sair usando 'lambda W'
      
      self.conteudo.pack_start(self.rotulo1, False, False, 0) #Componentes para Boxs
      self.msgBox.pack_start(self.mensagem, False, False, 0)
      self.conteudo.pack_start(self.msgBox, False, False, 0)
      self.boxButton.pack_end(self.btnSair, False, False, 0)
      self.boxButton.pack_end(self.btnEnviar, False, False, 0)

      self.conteudo.pack_start(self.boxButton, False, False, 0)
      
      self.janela.add(self.conteudo) #inserimos o box pricipal na janela
   
   def fechar(self, widget, window): #evento Fechar
      window.hide() #minimizar janela
      gtk.main_quit() #finalizar laço da GTK
      print "\n\n" #descer duas linhas
   
   def ev_Enviar(self, widget, entry): #evento Enviar
      self.texto = entry.get_text() #buscar texto de entrada
      print "\n\n", self.texto #desce duas linhas na tela e imprime texto de entrada
   
   def show(self): #evento de carregar janela
      self.janela.show_all() #carregar janela e todos os seus componentes

princ = j_princ() #variável na janela

if __name__ == "__main__":
   princ.show() #iniciar janela
   gtk.main() #iniciar laço GTK
