package Recipes;

public class RecipeNotFoundException extends RuntimeException {
    RecipeNotFoundException(Long id){
        super(String.format("Recipe with id %s not found", id));
    }
}
