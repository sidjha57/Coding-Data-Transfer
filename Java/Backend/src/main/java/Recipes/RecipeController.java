package Recipes;


import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;


@RestController
public class RecipeController {

    private RecipeRepository repository;

    // Dependency injection
    public RecipeController(RecipeRepository repository) {
        this.repository = repository;
    }
    @GetMapping("/recipes")
    List<Recipe> all(){
        return repository.findAll();
    }

    @GetMapping("/recipe/{id}")
    Recipe get(@PathVariable Long id){
        return repository.findById(id)
                .orElseThrow(() -> new RecipeNotFoundException(id));
    }

    @PostMapping("/recipes")
    Recipe save(@RequestBody Recipe newRecipe){
        return repository.save(newRecipe);
    }

    @DeleteMapping("/recipe/{id}")
    void delete(@PathVariable Long id){
        repository.deleteById(id);
    }

    @PutMapping("/recipe/{id}")
    Recipe update(@PathVariable Long id, @RequestBody Recipe newRecipe){
        return repository.findById(id).map(recipe -> {
            recipe.setName(newRecipe.getName());
            recipe.setIngredients(newRecipe.getIngredients());
            return repository.save(recipe);
        }).orElseGet(() -> {
            newRecipe.setId(id);
            return repository.save(newRecipe);
        });
    }
}
