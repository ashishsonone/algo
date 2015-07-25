import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Base{
    public static boolean isVisible;

    void onResume(){
        isVisible = true;
    }

    void onPause(){
        isVisible = false;
    }
}
