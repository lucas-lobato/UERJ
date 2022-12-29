<<<<<<< HEAD
public interface huggable{

    public abstract int hugg(int intent);
    
    public abstract int push(int intent);

    public abstract int touch(int intent);

}

class person implements huggable{

    @Override
    public int hugg(int intent){
=======
class person implements huggable{

    @Override
    public int hugg(int teddyBear){
>>>>>>> a310f568673cf2445fae79a081d83f9ee6f26164
        return 1;
    }

    @Override
<<<<<<< HEAD
    public int push(int intent){
=======
    public int push(int person){
>>>>>>> a310f568673cf2445fae79a081d83f9ee6f26164
        return 1;
    }

    @Override
<<<<<<< HEAD
    public int touch(int intent){
=======
    public int touch(int pet){
>>>>>>> a310f568673cf2445fae79a081d83f9ee6f26164
        return 1;
    }
}

<<<<<<< HEAD
class teddyBear implements huggable{

    @Override
    public int hugg(int intent){
        return 1;
    }

    @Override
    public int push(int intent){
=======
///////////////////////////////////////

class videoGame implements disconnectable{

    @Override
    public int connect(int videoGame){
>>>>>>> a310f568673cf2445fae79a081d83f9ee6f26164
        return 1;
    }

    @Override
<<<<<<< HEAD
    public int touch(int intent){
        return 1;
    }
}
///////////////////////////////////////

public interface disconnectable{

    public abstract int connect(boolean value);
    
    public abstract int disconnect(boolean value);

    public abstract int turnOff(boolean value);

}

class VideoGame implements disconnectable{

    @Override
    public int connect(boolean value){
        return false;
    }

    @Override
    public int disconnect(boolean value){
        return true;
    }

    @Override
    public int turnOff(boolean value){
        return true;
    }
}

class television implements disconnectable{

    @Override
    public int connect(boolean value){
        return true;
    }

    @Override
    public int disconnect(boolean value){
        return false;
    }

    @Override
    public int turnOff(boolean value){
        return false;
=======
    public int disconnect(int television){
        return 1;
    }

    @Override
    public int turnOff(int noteBook){
        return 1;
>>>>>>> a310f568673cf2445fae79a081d83f9ee6f26164
    }
}
