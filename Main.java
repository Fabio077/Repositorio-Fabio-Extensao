// 1. Interface Bonificavel
interface Bonificavel {
    double calcularBonus();
}

// 2. Classe abstrata Funcionario
abstract class Funcionario {
    protected String nome;
    protected double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public abstract void mostrarDetalhes();
}

// 3. Classes filhas
class Gerente extends Funcionario implements Bonificavel {
    private String departamento;

    public Gerente(String nome, double salario, String departamento) {
        super(nome, salario);
        this.departamento = departamento;
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Gerente: " + nome + ", Salário: " + salario + ", Departamento: " + departamento);
    }

    @Override
    public double calcularBonus() {
        return salario * 0.2; // 20% de bônus
    }
}

class Estagiario extends Funcionario implements Bonificavel {
    private int duracaoMeses;

    public Estagiario(String nome, double salario, int duracaoMeses) {
        super(nome, salario);
        this.duracaoMeses = duracaoMeses;
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Estagiário: " + nome + ", Salário: " + salario + ", Duração: " + duracaoMeses + " meses");
    }

    @Override
    public double calcularBonus() {
        return salario * 0.05; // 5% de bônus
    }
}

// 4. Programa principal
public class Main {
    public static void main(String[] args) {
        Funcionario[] funcionarios = new Funcionario[4];

        funcionarios[0] = new Gerente("Alice", 8000, "Financeiro");
        funcionarios[1] = new Estagiario("Bob", 1500, 6);
        funcionarios[2] = new Gerente("Carlos", 10000, "TI");
        funcionarios[3] = new Estagiario("Diana", 1800, 12);

        System.out.println("Detalhes e bônus dos funcionários:\n");
        for (Funcionario f : funcionarios) {
            f.mostrarDetalhes(); // polimorfismo
            if (f instanceof Bonificavel) {
                Bonificavel b = (Bonificavel) f;
                System.out.println("Bônus: " + b.calcularBonus());
            }
            System.out.println();
        }
    }
}
