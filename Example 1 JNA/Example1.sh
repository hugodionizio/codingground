# Criação da Pasta de binários "bin"
mkdir bin

# Compilação e verificação da biblioteca em C
gcc -fPIC -c src/example1.c
gcc -shared -o bin/libexample1.so example1.o
rm example1.o
nm bin/libexample1.so

# Importação da biblioteca jna.jar
cp src/jna.jar bin/jna.jar
cd bin/
jar xvf jna.jar com/
rm jna.jar
cd ..

# Compilação do projeto em Java
javac -classpath src/jna.jar src/Example1.java -d bin/
cp -r src/META-INF bin/META-INF
cd bin
jar cvfm Example1.jar META-INF/MANIFEST.MF Example1.class Example1\$Example1.class com libexample1.so

# Execução do projeto em jar
java -jar Example1.jar
