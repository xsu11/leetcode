package com.xinsu;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ReadWriteLockHashMap {

    private Map<String, String> map = new HashMap<>();

    private ReadWriteLock rw = new ReentrantReadWriteLock();

    public void put(String key, String value) {
        rw.writeLock().lock();
        try {
            map.put(key, value);
        } finally {
            rw.writeLock().unlock();
        }
    }

    public String get(String key) {
        rw.readLock().lock();
        try {
            return map.get(key);
        } finally {
            rw.readLock().unlock();
        }
    }

    public void remove(String key) {
        rw.writeLock().lock();
        try {
            map.remove(key);
        } finally {
            rw.writeLock().unlock();
        }
    }

}
