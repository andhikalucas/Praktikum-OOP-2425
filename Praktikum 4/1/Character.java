class Character extends Unit implements Damageable {
    protected int score;

    public Character() {
        super("Player1",100);
        this.score = 0;
    }
    public Character(String name, int health, int score) {
        super(name,health);
        this.score = score;
    }
    public int getScore() {
        return this.score;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health <= 0) {
            System.out.println(this.name + " has been defeated");
        }
    }
    public void increaseScore(int points) {
        this.score += points;
    }
    public String toString() {
        // System.out.println(this.name + " [Health: " + this.health + ", Score: " + this.score + "]");
        String s = this.name + " [Health: " + this.health + ", Score: " + this.score + "]";
        return s;
    }
}