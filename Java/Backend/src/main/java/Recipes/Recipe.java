package Recipes;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;

import java.util.ArrayList;

@Entity
public class Recipe {
    private @Id @GeneratedValue Long id;
    private String name;
    private ArrayList<String> ingredients;

    public Recipe() {}
    public Recipe(String name, ArrayList<String> ingredients) {
        this.name = name;
        this.ingredients = ingredients;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public ArrayList<String> getIngredients() {
        return ingredients;
    }

    public void setIngredients(ArrayList<String> ingredients) {
        this.ingredients = ingredients;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

}
