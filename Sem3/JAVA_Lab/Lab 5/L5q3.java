class BankExc extends Exception{
    public BankExc(String msg){
        super(msg);
    }
}

class BankAcc{
    int bal = 50000;
    public void Withdraw(int amt) throws BankExc{
        if (amt > bal)
            throw new BankExc("Unabale to withdraw ammount:"+ amt);
        bal = bal - amt;
    }
}
class L5q3 {
    public static void main(String args[]){
        BankAcc A1 = new BankAcc();
        try{
            A1.Withdraw(70000); 
        }
        catch(BankExc e){
            System.out.println(e.toString());
        }
    }
}
