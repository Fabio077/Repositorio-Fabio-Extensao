@echo off
REM Compila todos os arquivos Java do projeto para a pasta 'out'
javac -d out src/controller/*.java src/model/board/*.java src/model/pieces/*.java src/view/*.java
if %errorlevel% neq 0 (
    echo Erro na compilacao!
    pause
) else (
    echo Compilacao concluida com sucesso.
    pause
)
