
interface MyCamera {
    void takePicture ();
    void recordVideo();

    // When a class implements a interface it can skip updating the default methods
    default void record4KVideos() {
        System.out.println("Recording 4K Videos");
    }
}

interface MyWifi {
    String[] getNetworks();
    void connectToNetwork(String network);
}

class MyCellPhone{
    void callNumber(int phoneNumber) {
        System.out.println("Calling "+ phoneNumber);
    }
    void pickCall() {
        System.out.println("Connecting... ");
    }


}

class MySmartPhone extends MyCellPhone implements MyWifi, MyCamera {
    @Override
    public void takePicture() {
        System.out.println("Taking Picture");
    }

    @Override
    public void recordVideo() {
        System.out.println("Taking Video");
    }

    @Override
    public String[] getNetworks() {
        System.out.println("Getting List of Networks");
        String[] networkList = {"Harry", "Prashanth", "Anjali5G"};
        return networkList;
    }

    @Override
    public void connectToNetwork(String network) {
        System.out.println("Connecting to " + network);
    }

    @Override
    public void record4KVideos() {
//        MyCamera.super.record4KVideos();
        System.out.println("Mera naam sid hai");
    }
}
public class ClassAndInterfaces {
    public static void main(String[] args) {
        MySmartPhone mS = new MySmartPhone();
        String[] ar = mS.getNetworks();

        for (String name: ar) {
            System.out.println(name);
        }
        mS.record4KVideos();


        // Polymorphism creating MySmartPhone object with MyCamera reference
        MyCamera cam = new MySmartPhone();
        // cam smartphone can only be used as a camera
        cam.record4KVideos();
    }
}
