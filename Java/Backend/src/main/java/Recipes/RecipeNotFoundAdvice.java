package Recipes;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

@RestControllerAdvice
public class RecipeNotFoundAdvice {
    @ResponseBody
    @ExceptionHandler(RecipeNotFoundException.class)
    @ResponseStatus(HttpStatus.NOT_FOUND)
    String recipeNotFoundHandler(RecipeNotFoundException ex){
        return ex.getMessage();
    }
}
