class NPC extends Unit implements Damageable, Interactable {
    private String dialogue;

    public NPC() {
        super("NPC1", 100);
        this.dialogue = "Hello there!";
    }
    public NPC(String name, int health, String dialogue){
        super(name, health);
        this.dialogue = dialogue;
    }
    public String getDialogue(){
        return this.dialogue;
    }
    public void setDialogue(String s){
        this.dialogue = s;
    }
    public void interact(){
        System.out.println(this.dialogue);
    }
    public void takeDamage(int damage) {
        
    }
    public String toString(){
        String s = this.name + " [Health: " + this.health + ", Dialogue: " + this.dialogue + "]";
        return s;
    }
}